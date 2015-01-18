/*
** LuaFileSystem
** Copyright Kepler Project 2003 (http://www.keplerproject.org/luafilesystem)
**
** $Id: lfs.h,v 1.5 2008/02/19 20:08:23 mascarenhas Exp $
*/

/* Define 'chdir' for systems that do not implement it */
#ifdef NO_CHDIR
#define chdir(p)	(-1)
#define chdir_error	"Function 'chdir' not provided by system"
#else
#define chdir_error	strerror(errno)
#endif

#ifdef _WIN32
#define chdir(p) (_chdir(p))
#define getcwd(d, s) (_getcwd(d, s))
#define rmdir(p) (_rmdir(p))
#define fileno(f) (_fileno(f))
#ifdef _MSC_VER
# define utime(p,t) (_utime(p,(struct _utimbuf*)t))
# ifdef mkdir
#  undef mkdir
# endif
# define mkdir(p,m) (_mkdir(p))
#endif
#endif


int luaopen_lfs (lua_State *L);
