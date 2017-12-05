require "rome_converter"

RSpec.describe RomeConverter do
	describe "RomeConverter.to_dec and RomeConverter.to_rome"
		context "when executed " do
			it "converts decimal number to roman" do
				for i in 1..4000 
					expect(RomeConverter.to_dec(RomeConverter.to_rome(i)).to eql i				
				end
			end
			it "makes 1231 into MCCXXXI" do
				expect(RomeConverter.to_rome(1231)).to eql "MCCXXXI"
			end
			it "makes 444 into CDXLIV" do
				expect(RomeConverter.to_rome(444)).to eql "CDXLIV"
			end
			it "makes 567 into DLXVII" do
				expect(RomeConverter.to_rome(567)).to eql "DLXVII"
			end
			it "makes 999 into CMXCIX" do
				expect(RomeConverter.to_rome(999)).to eql "CMXCIX"			
			end	
			it "makes MMCCCXII into 2312" do
				expect(RomeConverter.to_dec("MMCCCXII")).to eql 2312
			end
			it "makes CDXCIV into 494" do
				expect(RomeConverter.to_dec("CDXCIV")).to eql 494
			end
			it "makes DLXXVI into 576" do
				expect(RomeConverter.to_dec("DLXXVI")).to eql 576
			end
			it "makes CMXLIX into 949" do
				expect(RomeConverter.to_dec("CMXLIX")).to eql 949			
			end		
		end
end

