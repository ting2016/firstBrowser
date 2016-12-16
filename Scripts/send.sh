#!/bin/bash
#file="/etc/hosts"
SCRIPTS_DIR=`pwd`
PROJECT_DIR=`dirname $SCRIPTS_DIR`
PROJ_DIR=`dirname $PROJECT_DIR`
PROJECT_DIR_NAME=`echo ${PROJECT_DIR/$PROJ_DIR} | tr -d '/'`
echo "$SCRIPTS_DIR"
echo "$PROJECT_DIR"
echo "$PROJ_DIR"
echo "$PROJECT_DIR_NAME"
DATE=`date +%Y%m%d_%H%M%S`
tarFileName=$DATE"_"$PROJECT_DIR_NAME".tar.gz"
#exec64TarFileName=$DATE"_UbiServerFB_64Bit.tar.gz"
echo "$tarFileName"
cd $PROJ_DIR

if [ -f "$tarFileName" ]
then
        echo "$tarFileName found deleting"
        rm $tarFileName
else
        echo "$tarFileName not found."
fi

#rm -r $PROJECT_DIR/bin/moc; rm -r $PROJECT_DIR/bin/obj;
read -p "Press any key to start compress source code"
tar czvf $tarFileName --exclude=$PROJECT_DIR_NAME/.git --exclude=$PROJECT_DIR_NAME/bin/ --exclude=$PROJECT_DIR_NAME/Scripts/ $PROJECT_DIR_NAME

if [ -f "$tarFileName" ]
then
        echo "copying $tarFileName to 64Bit Compile Server [speak2kramer]"
        scp $tarFileName pdaadmin@10.0.0.251:/home/pdaadmin/Downloads
        rm $tarFileName
        cd $SCRIPTS_DIR
        ssh pdaadmin@10.0.0.251 "bash -s" < ./builtOnServer.sh $tarFileName  $DATE $PROJECT_DIR_NAME
        #scp pdaadmin@10.0.0.251:/home/pdaadmin/Downloads/$PROJECT_DIR_NAME/bin/$exec64TarFileName $PROJECT_DIR/bin/
else
        echo "$tarFileName not found."
fi

