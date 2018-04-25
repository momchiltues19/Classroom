class Su < ApplicationRecord
	belongs_to :users
	belongs_to :subscriptions
	
	
	#validates :type, length: {minimum: 2} if type == 0 # 0 -> teacher
	#validates :type, length: {maximum: 10} if type == 1 # 1 -> student  
end
