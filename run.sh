./bin/mono_euroc ./Vocabulary/ORBvoc.txt ./Examples/Monocular/EuRoC.yaml ./data/stereo_euroc_$1/cam0/data ./Examples/Monocular/EuRoC_TimeStamps/$2.txt > ./outputs/$1-log.txt
mv ./KeyFrameTrajectory.txt ./outputs/$1.csv
