/* $OpenBSD: includes.h,v 1.54 2006/07/22 20:48:23 stevesk Exp $ */

/*
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 * This file includes most of the needed system headers.
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

#ifndef INCLUDES_H
#define INCLUDES_H

#include "config.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE /* activate extra prototypes for glibc */
#endif

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h> /* For CMSG_* */

#ifdef HAVE_LIMITS_H
# include <limits.h> /* For PATH_MAX, _POSIX_HOST_NAME_MAX */
#endif
#ifdef HAVE_BSTRING_H
# include <bstring.h>
#endif
#ifdef HAVE_ENDIAN_H
# include <endian.h>
#endif
#ifdef HAVE_TTYENT_H
# include <ttyent.h>
#endif
#ifdef HAVE_UTIME_H
# include <utime.h>
#endif
#ifdef HAVE_MAILLOCK_H
# include <maillock.h> /* For _PATH_MAILDIR */
#endif
#ifdef HAVE_NEXT
# include <libc.h>
#endif
#ifdef HAVE_PATHS_H
# include <paths.h>
#endif

/*
 *-*-nto-qnx needs these headers for strcasecmp and LASTLOG_FILE respectively
 */
#ifdef HAVE_STRINGS_H
# include <strings.h>
#endif
#ifdef HAVE_LOGIN_H
# include <login.h>
#endif

#ifdef HAVE_UTMP_H
#  include <utmp.h>
#endif
#ifdef HAVE_UTMPX_H
#  include <utmpx.h>
#endif
#ifdef HAVE_LASTLOG_H
#  include <lastlog.h>
#endif

#ifdef HAVE_SYS_SELECT_H
# include <sys/select.h>
#endif
#ifdef HAVE_SYS_BSDTTY_H
# include <sys/bsdtty.h>
#endif
#ifdef HAVE_STDINT_H
# include <stdint.h>
#endif
#include <termios.h>
#ifdef HAVE_SYS_BITYPES_H
# include <sys/bitypes.h> /* For u_intXX_t */
#endif
#ifdef HAVE_SYS_CDEFS_H
# include <sys/cdefs.h> /* For __P() */
#endif
#ifdef HAVE_SYS_STAT_H
# include <sys/stat.h> /* For S_* constants and macros */
#endif
#ifdef HAVE_SYS_SYSMACROS_H
# include <sys/sysmacros.h> /* For MIN, MAX, etc */
#endif
#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h> /* for MAP_ANONYMOUS */
#endif
#ifdef HAVE_SYS_STRTIO_H
#include <sys/strtio.h>	/* for TIOCCBRK on HP-UX */
#endif
#if defined(HAVE_SYS_PTMS_H) && defined(HAVE_DEV_PTMX)
# if defined(HAVE_SYS_STREAM_H)
#  include <sys/stream.h>	/* reqd for queue_t on Solaris 2.5.1 */
# endif
#include <sys/ptms.h>	/* for grantpt() and friends */
#endif

#include <netinet/in.h>
#ifdef __TANDEM
# include <netinet/in6.h>
/* while we're at it... */
# include <fcntl.h>
# include <sys/time.h> /* struct timeval */
/*# include <floss.h(floss_utimes)>*/ /* scp.c, sftp-server.c */
# define MISSING_NFDBITS 1 /* not detected by configure */
# define MISSING_FD_MASK 1 /* not detected by configure */
typedef long fd_mask; /* Not supplied anymore */
# define __timespec_DEFINED /* Hack? */
#if 0
  extern const void * EVP_sha256(void); /* Hack? Needed by schnorr.c, OpenSSL issue? */
#endif
# undef HAVE__RES_EXTERN /* misdetected by configure? */
# define DISABLE_UTMPX /* might be done via ./configure --enable-utmpx=no ? */

/* SI_WRITE is obsolete, but still used in scp.c, sftp-client.c */
# define S_IWRITE S_IWUSR

/* atomicio.c, auth2.c, authfd.c, channels.c, clientloop.c , monitor.c, monitor_wrap.c, msg.c, mux.c, openbsd-compat/readpassphrase.c, readpass.c, roaming_common.c, roaming_dummy.c, scp.c, serverloop.c, sftp-client.c, sftp-server.c, ssh-agent.c, ssh-keyscan.c, ssh-pkcs11-client.c, ssh-pkcs11-helper.c, sshconnect.c, sshd.c */
# include <floss.h(floss_read)>
/* atomicio.c */
# include <floss.h(floss_readv)>
/* authfd.c, authfile.c, channel.c, clientloop.c, log.c, monitor_wrapxp.c, msg.c, mux.c, openbsd-compat/readpassphrase.c, progressmeter.c, roaming_common.c, roaming_dummy.c, scp.c, serverloop.c, sftp-client.c, sftp-server.c, sftp.c, ssh-agent.c, ssh-keyscan.c, ssh-pkcs11-client.c, ssh-pkcs11-helper.c, sshconnect.c, sshd.c */
# include <floss.h(floss_write)>
/* sftp-client.c */
# include <floss.h(floss_writev)>
/* clientloop.c, openbsd-compat/daemon.c, readpass.c. scp.c, ssh-pkcs11-client.c, ssh.c, sshconnect.c */
# include <floss.h(floss_fsync)>
/* sftp-client.c, sftp-server.c */
# include <floss.h(floss_fork)>
/* clientloop.c, openbsd-compat/bsd-misc.c, openbsd-compat/bsd-poll.c, serverloop.c, session.c, sftp-server.c, sftp.c, ssh-agent.c, ssh-agent.c, ssh-keyscan.c, ssh-pkcs11-helper.c, sshconnect.c, sshconnect2.c, sshd.c */
# include <floss.h(floss_getpwuid)>
/* readpass.c, scp.c, ssh-pkcs11-client.c */
# include <floss.h(floss_execlp)>
/* session.c, sftp.c, sshconnect.c, sshconnect2.c */
# include <floss.h(floss_execl)>
/* session.c */
# include <floss.h(floss_execve)>
/* sftp.c, ssh-agent.c */
# include <floss.h(floss_execvp)>
/* sshconnect.c, sshd.c */
# include <floss.h(floss_execv)>
/* ssh.c, uidswap.c, sshconnect.c */
# include <floss.h(floss_seteuid,)>
/* uidswap.c */
# include <floss.h(floss_setreuid)>
/* auth1.c, channels.c, loginrec.c, plattform.c, session.c, sshd.c */
# define SUPERUSER 65535
# define NSIG (SIGABEND+1)
#else
# define SUPERUSER 0
#endif /* __TANDEM */

#include <netinet/in_systm.h> /* For typedefs */
#ifdef HAVE_RPC_TYPES_H
# include <rpc/types.h> /* For INADDR_LOOPBACK */
#endif
#ifdef USE_PAM
#if defined(HAVE_SECURITY_PAM_APPL_H)
# include <security/pam_appl.h>
#elif defined (HAVE_PAM_PAM_APPL_H)
# include <pam/pam_appl.h>
#endif
#endif
#ifdef HAVE_READPASSPHRASE_H
# include <readpassphrase.h>
#endif

#ifdef HAVE_IA_H
# include <ia.h>
#endif

#ifdef HAVE_IAF_H
# include <iaf.h>
#endif

#ifdef HAVE_TMPDIR_H
# include <tmpdir.h>
#endif

#if defined(HAVE_BSD_LIBUTIL_H)
# include <bsd/libutil.h>
#elif defined(HAVE_LIBUTIL_H)
# include <libutil.h>
#endif

#if defined(KRB5) && defined(USE_AFS)
# include <krb5.h>
# include <kafs.h>
#endif

#if defined(HAVE_SYS_SYSLOG_H)
# include <sys/syslog.h>
#endif

#include <errno.h>

/*
 * On HP-UX 11.11, shadow.h and prot.h provide conflicting declarations
 * of getspnam when _INCLUDE__STDC__ is defined, so we unset it here.
 */
#ifdef GETSPNAM_CONFLICTING_DEFS
# ifdef _INCLUDE__STDC__
#  undef _INCLUDE__STDC__
# endif
#endif

#ifdef WITH_OPENSSL
#include <openssl/opensslv.h> /* For OPENSSL_VERSION_NUMBER */
#endif

#include "defines.h"

#include "platform.h"
#include "openbsd-compat/openbsd-compat.h"
#include "openbsd-compat/bsd-nextstep.h"

#include "entropy.h"

#endif /* INCLUDES_H */
