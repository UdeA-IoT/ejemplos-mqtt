from abc import ABC, abstractmethod

from kivy.event import EventDispatcher
from kivy.properties import StringProperty

import home

class Device(ABC, EventDispatcher):
    """ Class Device
        Attributes:    
    """
    topic_prefix = ""
    ONLINE_STATE = "100"
    OFFLINE_STATE = "-100"
    UNKNOWN = "-1"

    state = StringProperty("0")

    def __init__(self, id, state, connection_status, name, ref_home):
        self.id = id
        self.state = state
        self.connection_status = connection_status
        self.name = name
        assert isinstance(ref_home, home.Home)
        self.my_home = ref_home
        self.msg_count = 0
        super().__init__()

    ''' process_external_msg
        process a message incoming from a external component (GUI or Sever)
    '''

    @abstractmethod
    def process_external_msg(self, message):
        pass

    # TODO: refactor this method. opt1: create a concrete method with current implementation
    ''' process_internal_msg
        process a message incoming from a physical device
    '''

    def process_internal_msg(self, payload):
        print('PAYLOAD', payload)
        self.connection_status = self.ONLINE_STATE
        # TODO: create mechanism to set connectionState to "OFFLINE"
        #  when no message has been received during a given time
        self._process_internal_msg_on_device(payload)
        self.eval_state_to_report()
        pass

    @abstractmethod
    def _process_internal_msg_on_device(self, parameter_list):
        pass

    @abstractmethod
    def get_topic(self):
        pass

    def eval_state_to_report(self):
        print('Eval status to report to server')
        self.msg_count += 1
        # TODO: change explicit number 5 to a constant
        if self.msg_count == 5:
            msg_dict = {'home_id':self.my_home.HOME_ID, 'dev_id':self.id, 'msg':"ONLINE"}
            print(msg_dict)
            self.my_home.send_alive_msg(msg_dict)
            self.msg_count = 0

    def clean_count(self):
        self.msg_count = 0

    # @abstractmethod
    # def get_json(self, parameter_list):
    #   pass
