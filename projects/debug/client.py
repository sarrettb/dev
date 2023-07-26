import debug_pb2 

class DebugService(debug_pb2.DebugBase): 
    def SayHello(self, request, context)