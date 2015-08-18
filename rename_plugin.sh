#!/bin/bash
newname=$1
oldname="NetExample"
echo "$newname"
echo "$oldname"
find . -not -path '*/\.*' -type f -print0 | xargs -0 sed -i "s/$oldname/$newname/g"
#find . -type f -exec rename "s/$oldname/$newname/' '{}" \;
find . | sed -e "p;s/$oldname/$newname/" | xargs -n2 git mv
