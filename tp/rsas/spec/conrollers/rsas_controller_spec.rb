RSpec.describe RsasController, type: :controller do
	it "shows am rsa" do
		get :show, params: {id: 1}
		expect(response).to render_template :show
	end

	it "creates a new rsa" do
		expect {		
		post :create, params: {n: 5, e: 7, d: 3}
		}.to change {Rsa.count}.by(1)
		#expect(Rsa.count).to eq old_value+1	
	end
end
