require "rome_converter"

RSpec.describe RomeConverter do
	describe "RomeConverter.to_dec and RomeConverter.to_rome"
		context "when executed =" do
			it "converts decimal number to roman" do
				for i in 1..4000 
					expect(RomeConverter.to_dec(RomeConverter.to_rome)).to eql i				
				end
			end
			it "1231 => MCCXXXI" do
				expect(RomeConverter.to_rome(1231)).to eql "MCCXXXI"
			end
			it "444 => CDXLIV" do
				expect(RomeConverter.to_rome(444)).to eql "CDXLIV"
			end
			it "567 => DLXVII" do
				expect(RomeConverter.to_rome(567)).to eql "DLXVII"
			end
			it "999 => CMXCIX" do
				expect(RomeConverter.to_rome(999)).to eql "CMXCIX"			
			end	
			it "MMCCCXII => 2312" do
				expect(RomeConverter.to_dec("MMCCCXII")).to eql 2312
			end
			it "CDXCIV => 494" do
				expect(RomeConverter.to_dec("CDXCIV")).to eql 494
			end
			it "DLXXVI => 576" do
				expect(RomeConverter.to_dec("DLXXVI")).to eql 576
			end
			it "CMXLIX => 949" do
				expect(RomeConverter.to_dec("CMXLIX")).to eql 949			
			end		
		end
end

