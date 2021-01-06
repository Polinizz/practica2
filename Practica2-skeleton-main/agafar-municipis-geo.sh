
OUTPUT=localitzacio.csv
URL="https://analisi.transparenciacatalunya.cat/resource/wpyq-we8x.csv"

echo Iniciem la baixada de $OUTPUT
if command -v curl &> /dev/null
then
   curl --output $OUTPUT $URL
else
  wget $URL --output-document $OUTPUT
fi
echo Baixada finalitzada
echo \# >> $OUTPUT
