# Makefile

PROG=		leonhard

SRCS=		\
		main.cpp

INCDIRS=	\
		.

CXXFLAGS+=	-std=c++11

include mk/build.mk
