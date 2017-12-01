#	$OpenBSD: transfer.sh,v 1.3 2015/03/03 22:35:19 markus Exp $
#	Placed in the Public Domain.

tid="transfer data"

for p in ${SSH_PROTOCOLS}; do
	verbose "$tid: proto $p"
	rm -f ${COPY}
	${SSH} -n -q -$p -F $OBJ/ssh_proxy somehost cat ${DATA} > ${COPY}
	if [ $? -ne 0 ]; then
		fail "ssh cat $DATA failed"
	fi
	diff ${DATA} ${COPY}
	if [ $? -ne 0 ]; then
		fail "corrupted copy"
	fi

	# NonStop only supports up to 32k based on limits.h
	#for s in 10 100 1k 32k 64k 128k 256k; do
	for s in 10 100 1k 32k ; do
		verbose "proto $p dd-size ${s}"
		rm -f ${COPY}
		dd if=$DATA obs=${s} 2> /dev/null | \
			${SSH} -q -$p -F $OBJ/ssh_proxy somehost "cat > ${COPY}"
		if [ $? -ne 0 ]; then
			fail "ssh cat $DATA failed"
		fi
		# RSB Changed this to diff from cmp and removed ||
		diff ${DATA} ${COPY}
		if [ $? -ne 0 ]; then
			fail "corrupted copy"
			ls -l ${DATA} ${COPY}
		fi
	done
done
rm -f ${COPY}
