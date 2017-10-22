require 'csv'
file = File.new(ARGV[0])
csv = File.new(ARGV[1])
fixture = CSV.open(csv,'r') { |csv| csv.first}
csv_path = File.absolute_path(csv)  

check = 0
CSV.foreach(file) do |row| 
	result = 0
	heroku_url = row[5]

	r1 = `curl -s -F \"file=@.#{csv_path}\" #{heroku_url}/sums` 
   	r2 = `curl -s -F \"file=@.#{csv_path}\" #{heroku_url}/filters`  
	r3 = `curl -s -F \"file=@.#{csv_path}\" #{heroku_url}/intervals`
	r4 = `curl -s -F \"file=@.#{csv_path}\" #{heroku_url}/lin_regressions`

	if r1 == fixture[0].to_s  && r2== fixture[1].to_s && r3 == fixture[2].to_s && r4 == fixture[3].to_s
		result = 1
	else 
		result = 0
	end
	if check > 0 && !heroku_url.nil?
			puts "#{row[1]},#{row[2]},#{row[3]},#{row[4]},#{result}\n" 
	end
	check+=1
end 
