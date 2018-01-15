# Software Engineering

## 16.10
### Output
A_#_F_L_results.csv
### Fixating csv
ruby mp.rb csv1 csv2
### Asynchronic execution?

## 23.10
### To sum up...
1. Ruby & rails
   rvm, byndler, gems
2. Heroku
3. HTTP
   POST
4. curl
5. /sums, /filters ...
   controllers, params
6. Test -> Test on test
7. CSV
### New theme - privnote.com (1-2-3-4(+-1) weeks)
1. Make Heroku app
2. Have proper view and model
3. HTML; JSON, XML - harder than CSV
4. Log in; token trade - random secure numbers (public and private(also called a key)) 
5. Free - basic features 
   Register for ability to use password
   Pay for more than 20 symbols
6. SaaS - subscriptions
   
   certificate authority - makes sure that what we recieve came from where we think it did
      server -> CA1 -> root authority (you can be your own RA, but who will trust you... :'( )
BONUS. DIY public/private ciphering (for hashes)
### Task 1
1. Make Heroku app
2. Have text space and submit button (view)
   Bootstrap - makes CSS less awful
3. Model that returns message id
   Message - one thing - text
4. Makes link with said id (/messages/id)
m = Message.new; m.save -> ActiveRecord -> ORM -> PostGreSQL
BONUS. random generated id - how? (not rand; short URL)
       What does Youtube do? 

## 30.10
### Checking homework for today

### For next time aka Task2
1. /new -> Form: text area and submit button -> Post -> create -> html
2. make is so app can work with **curl**<br>
   notes/api -> POST curl -> **JSON** with this in it *{ "key":"value"; "key":[i] ... }*
   POST curl with JSON -> *{ "message":"..." }* ; *{ "url":"..."}*
3. XML *<message> ... </message>* ; *<url> ... </url>*
        respond_to(guide)
          format.html
          format.json
What to commit? Commit in the same github repo and deploy the same heroku app

## 06.11
### Checking homework 
* Further explanation on the process of cheking the first hw
* Checking the second hw
	* Talking about UTF-8 and ASCII
	* Checking Martin T...
		* we can go back in time
	* Checked Martin T, checking Kari...
		* rails parses JSON automatically
		* clearing kesh is hard, so is naming methods/variables
		* CamelCase 
		* non_camel_case 
		* in JAVA
			* if method returns - G  getAge
			* if method takes - S setAge
			* if method bools - I isAge
		* in Ruby
			* if bool - age?
		* using nokogiri - it is a parser 
			* Nokogiri::XML.fragment(request.body.read).content + checking if the content is messages and not sth else
	* Checked Kari, how to improve it
		* ctr + d in sublime is THE BEST - helps with redundancy 
		* @message = Mesasge.create(:message=>text), with text being the thing in @message.text
		* respond_to 
### Why does sharing code cause bugs - |__RANDOM__| 
* Many reasons, all of them take some %
	* 90% - redundancy
* Conclusion - don't be redundant 0_0
### HW for Wednesday is no no hae~, Kiko will check and tell us if we suck

## 13.11
### New teacher (kinda, more like a one- or two-time thing (apperantly not, it's a every-monday thing, I guess))
* TUES
### IPC Intro - (pipe.c, named_pipe.c)
* WIN32_API
* Pipe - you input sth & you output same th (also known as fifo)
* man 2 pipe 
* Inter class comunication == fork
* DRAWING TIME:
```
			P2
			|
P1----W==========R----P4
			|
			P3
__BUT__
P1---W=========R---P1
__*then we fork*__
P2	-								P2
	\									/
	 |>--W=======R--<|
	/									\
P1									P1
```
* mkfifo

## 20.11
* We still have no idea if we suck or not, how sad...
### Memory sharing (no sockets, wv they are)
* presentations will be posted stim, swh; Magi is to recieve them
* man shm_overview
* volatile - know, that this said mem can be changed, even when you don't think it can be, so beware of making temporary memory holders
* continue - break and act as if you weren't in the {} thingy (I guess heap? maybe?) you were in ([more here](https://www.tutorialspoint.com/cprogramming/c_continue_statement.htm))
### Next time we finish this up and then have some BONUS - talking about random stuff

## 27.11
* Forgot to save, we don't suck, bla bla bla
* HWs, they have grades 
	* Until Monday, maybe Wednesday if Kiko allows
* grep manual: 
	* -v - you see all the things that DON'T have what you specified
	* -w - you see only the thing specified as a word, not as part of one
	* -c - counts the number of lines

## 29.11
* More homework
### Homework 
* You are given a class - RomeConverter
	* to_rome - takes int, makes it a roman numerals _6 -> VI_ 
	* to_dec - takes roman numerals, makes it int _IX -> 9_
* RSpec
	* ~=~ 15 tests 
### In Class
* Install Rspec
* Make ruby file - Caesar
* Test with RSpec
* Make Caesar work (there is a gem)

## 6.12
* Check prev hw, get new one (EZ)
### In Class
* Checking homework
* `rspec` - we exec all the specs in spec
* `rspec *file name*` - we exec the specified spec
* `rspec *file name* --format d` - shows the tests instead of dots

1. `let - let(:converter) {RomeConverter.new}` - converter is created in do end and destroyed with at the end

```ruby
let(:converter) do
	#some code
	ImprovedRomeConverter.new
end
```
2. new - makes new object
	* Use it as less as possible

* describe vs context - context shows a diffrent context, describe shows the behaviour we expect
* you can use normal ruby code in tests, but that's not good practise as you then have to test the test and that causes infinite recursion
* `describe '#to_rome' do` - it describes a method, but Kiko does not likey it
### Homework(aka некст тайм)
* RSA - class
	* initializer(public,private)
	* encrypt(m) -> c
	* decrypt(c) -> m
	* key()
* RSA_spec
### [RSA](https://en.wikipedia.org/wiki/RSA_(cryptosystem))
* Asymetric description
* public and private keys
* person one uses person two's public key to send a message
* p2 gets the crypted message and can only use the his private key to decrypt it
* keys are very big (≈2^100) (alt + 240 - ≡ ; alt + 247 - ≈ ) 

## 11.12
* Homework remarks
* More time for hw

## 13.12
### In Class
* Checking homework
```ruby
class RSA
	self.new_key
	n
	e
	d
end

test = RSA.new(1,2,3)
```
* Running new makes an object (nothing new here)
	* calling for n would result in us getting 1, so the functions depend on the object
	* new_key does not depend on the object, meaning it should be static aka self
* Every object has functions and data
	* polymorphism -> static stops it, so it is not THAT good
* When encypting, we get a very big num that cannot be a char
	1. add to string and add something between them
	2. "You are not ready yet"
### Homework(фор некст тайм)
```ruby
class RSA
	initialize
	n
	e
	d
	new_key
	encrypt
	decrypt
end
```
* test file - which method(GET; POST; PUT; DELETE) 
	* POST url -> /new
	* GET /n -> /n/id
```
POST	/rsas - new_key								returns id
			 ?n = 1 & d = 4 & e = 5 - initialized
GET		/rsas/:id?values = public
						   private
						   all
POST	/rsas/:id/enc_messages?m = ...				returns id2
GET		/rsas/:id/enc_messages/:id2
POST	/rsas/:id/dec_messages?m
							   m_d = id2
```
* 3 controllers
	*rsas
	*enc_messages
	*dec_messages
* RSPEC for controller(hopefully not for next time, probably not)
* Code coverage - 85% of the code works
* JANUARY - simple graphic interface for stuff done on JS... ;;;;;;;;;;;;

## 20.12
### In Class 
* Checking homework
Question 1. url (Naichev)
	```
	()POST /rsas/:id/encrypt.
	vs
	[]POST /encrypt
	
	()GET /rsas/:id/encrypt/:id2
	vs
	[]GET /encrypt/:id
	```
	* [] - kvadratche
	* () - kruchke
	* Which is better?
		* Depends on the software requirenments and the client(in our case - the teacher)
		* You should keep it consistant 
Question 2. Pavlove asked for more time (we got it, _relate to first bullet in Homework_)
Question 3. Magi asked for more code in class
	* I am not sure if that is a good idea
Question 4. _Relate to second bullet in Homework_ (Boyan)
Question 5. Markov asked sth
Question 6. Alex asked about keys, Mitov couldn't give a straight answer
#### [SimpleCov](https://github.com/colszowka/simplecov)
* Checks line coverage
* rspec --init
* For Rspec, for sth else, for cucumber
### Homework(фор некст тайм which is 10.01.2018)
* The old homework + the rspecs (about 10)(maybe, I'm scared cause Mitov is going crazy; __new triger word unclocked - deadline__
* Look for RSAs in OpenSSL documentation because the thing in wikipedia is stupid
* Rspec that test controllers aka rspec for rails ('o') 
#### STEP-BY-STEP TUTORIAL 
1. Copy thing from Installation from [here](https://github.com/rspec/rspec-rails) and add it to the Gemfile
   run bundle insatall
2. Now write a spec for a controller by making a spec dir in the main place of the rails project
   mkdir spec
   mkdir spec/controllers
   mkdir spec/controllers/*controller name*_spec.rb
3. Write your rspec code :)
   Example:
```ruby
RSpec.describe *controller name* do
	it "returns message" do

	end
end 
```
4. rails generate rspec:install
5. bundle exec rspec
#### Learning JavaScript
1. Breathe
2. Breathe some more
3. Open [YouTube](https://www.youtube.com)
4. Search for "JavaScript in one hour"
5. Watch quietly and don't think too much
6. You now know JavaScript (apparently)
<<<<<<< HEAD

## 08.01
### In Class
* We start of with no wifi drama
### Homework(hopefuly there is none, we have enough as it is)

## 10.01
### In Class
* Starting rsa from scratch [here](https://github.com/momchiltues19/Classroom/tree/master/tp/rsas).
* `rails scafold block` does a thing
### Homework
* RSpec, I guess, you have a step by step and also an already made project (hopefully 2 of them)

# Project information
* Have an idea
* Teams of two people (or 3 if uncountable)
* _Have a project until the end of Feb_
* Train on selling your ideas with one another
* Beggining of new Term - sell your idea to Kiko
	* e.g - fitness helper - 2 paragraphs (2 mins) about your project aka know what you are doing
		  - board game facebook/ebay/forum/dating site 
		  - phone cofefe maker control
* top 50 biggest Venture Funds or ideas
### Suggestions - look into mobile (tech of the future)
* Mitov wants a fridge - recipe - where to buy products

1. Open the Play Store	
2. Look at the top 100 most popular apps
3. Try them out
4. See what they are about
5. Make and app

### Suggestions - Apps or Games
* Mitov will exlain what a good game is
* If it is in the unity tutorials, don't do it
* _BE CREATIVE_
* Make it fun
* Mitov likes the Bridge Consturtor franchise
* Make the app/game free, but add microtransactions
* Ads
* If you can put it on the Play Store, than it is good

### Suggestions - if your parents have a business, help them with it
* Automatization
* TUES entrance fill in form software
* AzTUES software checks people who have tagged in TUES
* AI that answers calls/app that analizes customer's online information by their name and maybe face

### Suggestions - WEB
* look at the top 500 websites
* make lesson from stackoverflow posts
	* top 50 problems with rails - pay 5$, get your solutions
* PT information
* Fitness information
* Outside sport stuff information

## Realisation
### II. FEBRUARY
* Have an idea
* Have a name for your idea 
* Have a plan for your idea - have it electronically
##### User Story - user side information about what something does that can fit on a info card/postit note (15-20 words)
* Having 20-30-40 user stories is ideal (user stories have nothing to do with who is making them)
* 500 is good, if you have the motivation
* _Give each Story time it would take to implement_ - more than 1 - 16, 10 is the best, if less - just make the thing, if more - seperate it into part
* When adding all the times, you get a number (e.g 1000), plan work per person per week (e.g _20, but it is best to be less than that_) and see how many weeks it will take (e.g 25)
* Planning is useful, but it won't look great at first
* With time, planning gets better, if you do it enough
* Know yourself and your partner
* Role-play a business - money managment, time managment, thinking about the konkurencia
* _Prioritize_ - 1 has the least amount of tasks, 2 has the most amount of tasks, 3 is extra stuff you won't have time for but would still be good to implemtent in the future so should be taken into consideration when doing the tasks in 1 and 2
* Split the work, just don't think that if you have 6 1 tasks, each of you has to do 3 

### III. MARCH

### IV. APRIL

### V. MAY <- тук кико ще се заяжда
* Wiki of the project 
* GitHub history
* VIDEO - trying to sell the project...
	* Be original and don't over do it
	* Have fun
## General tips
* Never only do one thing (so like backend, user inteface, design and so on should be done at the same time, little by little)
* Sell your idea and lie about it if you can to get people pumped, get money, and then do it aka the Patreon model of business
* Relax, Mitov will help (it can be embeded, that gives me an idea)
