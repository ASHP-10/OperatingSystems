echo "Enter n";
read n;
case $n in
1)
echo $n
;;
2)
((n = n+1))
echo $n
;;
esac