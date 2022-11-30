

i=0

while [ $i -lt 1 ]
do	
	if [[ $i -eq 0 ]]
	then
		url="https://www.sciencedirect.com/search?qs=%28virtual%20OR%20Metaverse%29%20AND%20service"
	fi
	echo $url
	year=1999
	while [[ year -lt 2024 ]]
	do	
		url1="$url&years=$year"
		j=0
		while [[ j -lt 21 ]]
		do
			jj=$((100*$j))
			url2="$url1&show=100&offset=$jj"
			echo $url2
			bash save_page_as $url2 --browser google-chrome --destination "/home/kim415/Dropbox/hmc_slr/sciencedirect/test_page-$i-$j-$year.html" --load-wait-time 5 --save-wait-time 5
			j=$[$j+1]

		done
		year=$[$year+1]

	killall chrome
	done
	i=$[$i+1]
done

