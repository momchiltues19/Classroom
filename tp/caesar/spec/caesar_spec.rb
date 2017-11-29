require "caesar"

describe Caesar do
	describe ".crypt" do
		context "given two strings" do
			it "returns VWGU" do
				expect(Caesar.crypt('s', 's')).to eql "VWGU"	
			end		
		end 
end

end

