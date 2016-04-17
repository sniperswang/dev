for d in *; do 
	if [ "$d" != "makeAll.sh" ]
	then
	 cd $d
	 echo "make clean for $d ..."
	 make clean
	 cd ..
	fi
 done
