RSpec.describe Rsa do
	it "encrypts" do
		r = Rsa.new
		expect(r.encrypt("blabla")).to eq "qwerty" 
	end
end
