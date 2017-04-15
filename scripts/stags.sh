ctags \
	--langdef=stanza \
	--langmap=stanza:.stanza \
	--regex-stanza="/^[ \t]*(public )?(protected )?(lostanza )?defn[ \t]+([a-zA-Z0-9_\-]+)/\4/f,function,functions/" \
	--regex-stanza="/^[ \t]*(public )?(protected )?(lostanza )?deftype[ \t]+([a-zA-Z0-9_\-]+)/\4/t,type,types/" \
	--regex-stanza="/^[ \t]*(public )?(protected )?(lostanza )?va[lr][ \t]+([a-zA-Z0-9_\-]+)/\4/v,value,values & variables/" \
	--regex-stanza="/^[ \t]*extern[ \t]+([a-zA-Z0-9_\-]+)/\1/e,extern,external c mappings/" \
	--regex-stanza="!^[ \t]*(import|defpackage)[ \t]+([a-zA-Z0-9_\-\/]+)!\2!p,package,packages!" \
	src/*

# 	
#sdasd
