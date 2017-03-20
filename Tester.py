import AbstractTesterClass
import socket

class Tester(AbstractTesterClass.aTesterClass):
    
    def __init__(self):
        self.passwords_to_test = ("1234","4321","1111")
        self.index = 0
        self.BUFFER_SIZE = 1024  
        self.should_continue = True

    def perform_test(self, ip, port):

        print("Trying password "+self.passwords_to_test[self.index])

        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, int(port)))
        data = s.recv(self.BUFFER_SIZE)
        s.send(self.passwords_to_test[self.index])
        data = s.recv(self.BUFFER_SIZE)
        s.close()
        if "welcome" in data.lower():
            print "password seems to be",self.passwords_to_test[self.index]
            self.should_continue = False
        else:
            print "password is not",self.passwords_to_test[self.index],"(retrun string is \""+data.strip()+"\")"
            self.index +=1
        

    def should_continue_testing(self):
        return self.index < len(self.passwords_to_test) and self.should_continue
