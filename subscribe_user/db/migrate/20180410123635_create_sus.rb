class CreateSus < ActiveRecord::Migration[5.1]
  def change
    create_table :sus do |t|
      t.integer :id_u
      t.integer :id_s
      t.integer :type

      t.timestamps
    end
  end
end
