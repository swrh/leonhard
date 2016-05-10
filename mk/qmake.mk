# qmake.mk
#
# Copyright (c) 2005-2013 Fernando Silveira <fsilveira@gmail.com>
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#      This product includes software developed by Fernando Silveira.
# 4. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

ifndef qmake.mk
qmake.mk=		y

ifndef DOTMKDIR
	DOTMKDIR:=		$(dir $(lastword $(MAKEFILE_LIST)))

	dotmk_tmp:=		$(shell [ ! -d $(DOTMKDIR) ] || echo $(DOTMKDIR))
	ifeq ($(dotmk_tmp),)
		dotmk_tmp:=	$(error Couldn't determine DOTMKDIR variable automatically)
	endif

	ifeq ($(findstring else-if,$(.FEATURES)),)
		dotmk_tmp:=	$(error You need a newer version of GNU make to use `dotmk')
	endif

endif

include $(wildcard $(DOTMKDIR)/mk.d/*.mk)

ifneq ($(wildcard $(DOTMKDIR)/qmake-local.mk),)
	include $(DOTMKDIR)/qmake-local.mk
endif


QMAKE?=		qmake

ifdef PRO
PROS+=		$(PRO)
endif


# pro files

define PRO_template
DEFAULT_TARGETS+=	$(patsubst %.pro,%,$(notdir $(1)))
Makefile-$(notdir $(1)): $(1)
	@$$(QMAKE) -o Makefile-$(notdir $(1)) $(1)

.PHONY: $(patsubst %.pro,%,$(notdir $(1)))
$(patsubst %.pro,%,$(notdir $(1))): Makefile-$(notdir $(1))
	@$$(MAKE) -f Makefile-$(notdir $(1)) all

INSTALL_TARGETS+=	$(patsubst %.pro,%,$(notdir $(1)))_install
$(patsubst %.pro,%,$(notdir $(1)))_install: Makefile-$(notdir $(1))
	@$$(MAKE) -f Makefile-$(notdir $(1)) install

CLEAN_TARGETS+=	$(patsubst %.pro,%,$(notdir $(1)))_clean
$(patsubst %.pro,%,$(notdir $(1)))_clean: Makefile-$(notdir $(1))
	@$$(MAKE) -f Makefile-$(notdir $(1)) clean

DISTCLEAN_TARGETS+=	$(patsubst %.pro,%,$(notdir $(1)))_distclean
$(patsubst %.pro,%,$(notdir $(1)))_distclean: Makefile-$(notdir $(1))
	@$$(MAKE) -f Makefile-$(notdir $(1)) distclean
	@$$(RM) Makefile-$(notdir $(1))
endef

$(foreach pro,$(PROS),$(eval $(call PRO_template,$(pro))))

.PHONY: all install uninstall clean distclean
all: $(filter-out $(DISABLE_TARGETS),$(DEFAULT_TARGETS))
ifeq ($(filter install,$(DISABLE_TARGETS)),)
install: $(filter-out $(DISABLE_TARGETS),$(INSTALL_TARGETS))
endif
ifeq ($(filter uninstall,$(DISABLE_TARGETS)),)
uninstall: $(filter-out $(DISABLE_TARGETS),$(UNINSTALL_TARGETS))
endif
ifeq ($(filter clean,$(DISABLE_TARGETS)),)
clean: $(filter-out $(DISABLE_TARGETS),$(CLEAN_TARGETS))
endif
ifeq ($(filter distclean,$(DISABLE_TARGETS)),)
distclean: $(filter-out $(DISABLE_TARGETS),$(DISTCLEAN_TARGETS))
endif

.DEFAULT_GOAL:=		all

endif # ndef qmake.mk
