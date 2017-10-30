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
