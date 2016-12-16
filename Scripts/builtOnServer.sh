#!/bin/bash

echo $1 $2 $3 
export PATH=$HOME/gcc-4.9.3/bin:$PATH
echo `gcc -v`
cd /home/pdaadmin/Downloads
rm -r $3
tar zxvf $1
rm $1
cd $3/bin
rm -rf *
#sed -i -- 's/QMAKE_POST_LINK/#QMAKE_POST_LINK/g' ../$3.pro
/usr/lib/Qt/5.5/gcc_64/bin/qmake ../
make -j2
strip $3
#sudo cp UbiServer /var/lib/Datawind/$3_old_UbiServer -f
#sudo cp UbiServer /var/lib/Datawind/ -f
#sudo rm /var/log/datawind/http_logs/ubiserver/session_logs/*.log-done
#tar czvf $2 UbiServer


