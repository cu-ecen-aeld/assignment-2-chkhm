
if [ $# -lt 2 ]; then
    echo "need to parameters: first parameter is a writefile and second is writestr string"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname $writefile)"
echo "${writestr}" > ${writefile}
