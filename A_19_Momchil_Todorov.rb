require 'csv'
file = ARGV[0]

check = 0
CSV.foreach(input_file) do |row| 
	result = 0
	heroku_url = row[5]

	r1 = `curl -s -F \"file=@./A_19_Momchil_Todorov.csv\" #{heroku_url}/sums` 
   	r2 = `curl -s -F \"file=@./A_19_Momchil_Todorov.csv\" #{heroku_url}/filters`  
	r3 = `curl -s -F \"file=@./A_19_Momchil_Todorov.csv\" #{heroku_url}/intervals`
	r4 = `curl -s -F \"file=@./A_19_Momchil_Todorov.csv\" #{heroku_url}/lin_regressions`

	if r1 == "528"  && r2== "256" && r3 == "525" && r4 == "1.000000,0.000000"
		result = 1
	else 
		result = 0
	end
	if check > 0 && !heroku_url.nil?
			puts "#{result}\n" 
	end
	check+=1
end 
