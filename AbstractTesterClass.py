

class aTesterClass:
	''' bstract class which defines the way a tester class should look like	'''
	def perform_test( self, ip, port ):
		raise NotImplementedError( "Should have implemented this" )

	def should_continue_testing(self):
		raise NotImplementedError( "Should have implemented this" )