## "Cheat Sheet" for rails exam (not really cheating)

### Many-to-many validation - check that there is only one teacher teaching each subject
```Ruby
validate do
    TeacherSchool.where(school_id: school_id).each do |ts|
        if ts.teacher.subject == Teacher.find(teacher_id).subject
            self.errors.add(:base, "ddd")
        end
    end
end
```
### Many-to-many association
```Ruby
has_many :teacher_schools
has_many :schools, through: :teacher_schools
```
### Single validation - check if teacher has unique first and last name
```Ruby
validate do
    if Teacher.exists?(first_name: first_name, last_name: last_name)
        self.errors(:base, "Can not have duplicate fist and last name")
    end
end
```
OR
```Ruby
validates :first_name, uniqueness: { scope: :last_name, 
    message: "There is another teacher with this name already" }
```
### Single validation - check field content
```Ruby
validate do
    if color != "red" && color !="green" && color != "blue"
      errors.add(:color, "Can be only green, red, blue")
    end
end
```
### One-to-many validation - only 3 cars of the same color in a year
```Ruby
validate :validates_cars_in_manufacture

private
def validates_cars_in_manufacture
    count = Car.where(color: color, year: year, manufacture_id: manufacture_id).count
    if count >= 3
        errors.add(:cars, "Max number of cars with this color in this year reached")
    end
end
```
### One-to-many validation - only 3 comps with the same arch in a month
```Ruby
validate :validates_cars_in_manufacture

private
def validates_with_count
    if Computer.
        where(manufacture_id: manufacture_id, architecture: architecture).
        where('date BETWEEN ? AND ?', date.beginning_of_month, date.end_of_month).
        count >=3
      errors.add(:computers, "More the 3 comps with the same arch in the given month can't be created")
    end
end
```
