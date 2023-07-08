cd kern3
cd linux-6.0.9
wget https://raw.githubusercontent.com/gopi487krishna/ArtixConfig/main/config-rev-9-gold
make mrproper
cp config-rev-9-gold .config
make nconf ig
make -j2
make modules
make modules_install