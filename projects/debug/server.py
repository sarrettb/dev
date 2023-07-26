import debug_pb2 
import concurrent.futures 

class DebugService(debug_pb2.DebugBase): 
    def SayHello(self, request, context):
        print(request)

    def serve(self):
        server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        route_guide_pb2_grpc.add_RouteGuideServicer_to_server(
            RouteGuideServicer(), server)
        server.add_insecure_port('[::]:50051')
        server.start()
        server.wait_for_termination()