#!/bin/sh
#       $OpenBSD: sshd-log-wrapper.sh,v 1.4 2016/11/25 02:56:49 dtucker Exp $
#       Placed in the Public Domain.
#
# simple wrapper for sshd proxy mode to catch stderr output
# sh sshd-log-wrapper.sh /path/to/logfile /path/to/sshd [args...]

# set -x
log=$1
shift

# TEMP_FILE=/tmp/$RANDOM.sshd.test
exec "$@" -E$log # > $TEMP_FILE
# cat $TEMP_FILE
