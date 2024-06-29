
if [ $# -lt 2 ]; then
    echo "need to parameters: first parameter is filesdir and second is search string"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d ${filesdir} ]; then
    echo "input folder does not exist."
    exit 1
fi

x=`grep -lr ${searchstr} ${filesdir} 2> /dev/null| wc -l`
y=`grep -r ${searchstr} ${filesdir} 2> /dev/null | wc -l`

echo "The number of files are ${x} and the number of matching lines are ${y}"

