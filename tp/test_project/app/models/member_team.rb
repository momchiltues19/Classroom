class MemberTeam < ApplicationRecord
	validate do
		new_team = Team.find(self.team_id)
		new_color = new_team.color
		member = Member.find(self.member_id)
		MemberTeam.where(member_id: self.member_id).each do |mt|
			team = Team.find(mt.team_id)
			if team.color == new_color 
				errors.add(:team, "is this valid? NO!!")
			end
		end
	end
end
