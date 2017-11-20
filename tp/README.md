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
      P2
      |
P1----W==========R----P4 /
      |
      P3
__BUT__
P1---W=========R---P1
__*then we fork*__
P2\                 /P2
   |>--W=======R--<|
P1/                 \P1
* mkfifo

## 20.11
* We still have no idea if we suck or not, how sad...
### Memory sharing (no sockets, wv they are)
* presentations will be posted stim, swh; Magi is to recieve them
* man shm_overview
* volatile - know, that this said mem can be changed, even when you don't think it can be, so beware of making temporary memory holders
* continue - break and act as if you weren't in the {} thingy (I guess heap? maybe?) you were in [more here](https://www.tutorialspoint.com/cprogramming/c_continue_statement.htm) 
### Next time we finish this up and then have some BONUS - talking about random stuff
