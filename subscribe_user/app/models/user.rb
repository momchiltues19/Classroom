class User < ApplicationRecord
	has_many :sus
	has_many :subscriptions, through: :sus
	
end
