class Subscription < ApplicationRecord
	has_many :sus
	has_many :users, through: :sus

	validate :check_plan_price

	def check_plan_price
		if self.subscription < 10
			if self.subcription.subscription_users.
			   where(role: "teacher").count >= 2 && self.role == "teacher"
			
				self.errors.add(:user, "text")
				throw :abort			
			end
			if self.subcription.subscription_users.
			   where(role: "student").count >=10 && self.role == "student"
			
				self.errors.add(:user, "text")
				throw :abort
			end
		end	
	end
end
