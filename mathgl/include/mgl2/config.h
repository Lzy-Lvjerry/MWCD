#ifndef _MGL_CONFIG_H_
#define _MGL_CONFIG_H_

#define MGL_VER2 	4.4	// minor version of MathGL 2.* (like 1.3 for v.2.1.3)
#define MGL_VER_MAJOR 	2
#define MGL_VER_MINOR 	4
#define MGL_VER_PATCH 	4
#define MGL_VERSION 	(2000+4.4)
#define MGL_VER_STRING 	"2.4.4"

#define MGL_USE_DOUBLE	1

#ifdef WIN32	// a man ask to use built-in font under Windows
#define MGL_DEF_FONT_NAME	""
#else
#define MGL_DEF_FONT_NAME	"STIX"
#endif
#define MGL_INSTALL_DIR	"C:/Program Files (x86)/MathGL2"

#if defined(_MSC_VER) || defined(__BORLANDC__)
#define MGL_SYS_NAN		0
#define MGL_HAVE_PTHREAD	0
#define MGL_HAVE_PTHR_WIDGET	0
#define MGL_HAVE_ATTRIBUTE	0
#define MGL_HAVE_C99_COMPLEX	0
#else
#define MGL_SYS_NAN			1
#define MGL_HAVE_PTHREAD	1
#define MGL_HAVE_PTHR_WIDGET	1
#define MGL_HAVE_ATTRIBUTE	1
#define MGL_HAVE_C99_COMPLEX	0
#endif

#define MGL_SIZEOF_LONG	4
#define MGL_HAVE_LTDL	0
#define MGL_HAVE_RVAL	1
#define MGL_HAVE_ZLIB	1
#define MGL_HAVE_PNG	1
#define MGL_HAVE_GSL	0
#define MGL_HAVE_OPENGL	1
#define MGL_HAVE_OMP	0
#define MGL_HAVE_JPEG	1
#define MGL_HAVE_GIF	1
#define MGL_HAVE_PDF	0
#define MGL_HAVE_HDF4	0
#define MGL_HAVE_HDF5	0
#define MGL_USE_GETTEXT	0
#define MGL_FONT_PATH	"C:/Program Files (x86)/MathGL2/fonts"
#define MGL_HAVE_FL_COPY	1

#endif
