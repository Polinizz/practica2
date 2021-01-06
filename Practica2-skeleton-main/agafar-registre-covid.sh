#!/bin/bash

OUTPUT=registre-covid.csv
URL="https://analisi.transparenciacatalunya.cat/api/views/jj6z-iyrp/rows.csv?accessType=DOWNLOAD"

echo Iniciem la baixada de $OUTPUT
if command -v curl &> /dev/null
then
   curl --output $OUTPUT $URL
else
  wget $URL --output-document $OUTPUT
fi
echo Baixada finalitzada
echo \# >> $OUTPUT
