for d in *; do 
	if [ "$d" != "makeClean.sh" ]
	then
	 cd $d
	 echo "make clean for $d ..."
	 make clean
	 cd ..
	fi
 done
