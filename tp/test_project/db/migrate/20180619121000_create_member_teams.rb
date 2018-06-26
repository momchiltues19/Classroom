class CreateMemberTeams < ActiveRecord::Migration[5.1]
  def change
	drop_table :member_teams

    create_table :member_teams do |t|
    	t.references :team
    	t.references :member

    	t.timestamps
    end
  end
end
