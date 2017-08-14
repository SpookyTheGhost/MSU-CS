class clock(object):
    def __init__(self,hours=0,minutes=0,seconds=0):
        ''' takes hours, minutes, seconds as named arguments. Each parameter is an integer.'''
        self.hours= hours
        self.minutes = minutes
        self.seconds = seconds
        

    def str_update(self,input_str=''):
        time=input("Please enter a time in form hour:minutes:seconds: ")
        hours,minutes,seconds = [int(n) for n in time.split('\n')]
        if valid_time(hours,minutes,seconds):
            self.hours = hours
            self.minutes = minutes
            self.seconds = seconds
        else:
            print("invalid time, clock not changed")

    def print_clock(self):
            ''' Print the date in a nice format'''
            print("This is: %s %d %d" % (self.hours,self.minutes,self.seconds))        
  
    def add_clocks(self,__init__):
        '''updates the clock'''
        hours_update = self.hours + hours
        minutes_update = self.minutes + minutes
        seconds_update = self.seconds + seconds
        if minutes_update > 60:
            extra = divmod(self.minutes,60)
            hours_update+extra[1]
        if seconds_update > 60:
            extra1 = divmod(self.seconds,60)
            minutes_update + extra1[1]
        #new_clock = 
#new_clock = hours_update:minutes_update:seconds_update
        
##def main(constructor, str_update,print_clock, add_clocks):
##    print('hi')
##main()
    
clock().add_clocks()
