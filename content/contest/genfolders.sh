chmod +x bld
chmod +x bldf
for f in {a..z}
do
    mkdir $f
    cp main.cpp bld bldf $f
done
