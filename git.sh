#!/bin/bash

if [ "$1" == "aca" ]
then
    if [ "$2" == "init" ]
    then
        git remote add upstream https://github.com/zivlakmilos/Parmecium.git
    fi
    if [ "$2" == "start" ]
    then
        git fetch upstream
        git checkout master
        git merge upstream/aca
    elif [ "$2" == "commit" ]
    then
        git add *
        git commit -m "$3" -a
        git push
    fi
elif [ "$1" == "zi" ]
then
    if [ "$2" == "start" ]
    then
        git pull
        git request-pull master https://github.com/AionCode/Parmecium.git aca
        #git request-pull master https://github.com/zivlakmilos/Parmecium.git aca
        git pull https://github.com/AionCode/Parmecium.git master
    elif [ "$2" == "commit" ]
    then
        git add *
        git commit -m "$3" -a
        git push
    fi
fi
