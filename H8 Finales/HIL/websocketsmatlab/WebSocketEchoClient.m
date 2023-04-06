classdef WebSocketEchoClient < WebSocketClient
    
    properties
    end
    
    methods
        function obj = WebSocketEchoClient(varargin)
            %Constructor
            obj@WebSocketClient(varargin{:});
        end
    end
    
    methods (Access = protected)
        function onOpen(obj,message)
            fprintf('%s\n',message);
        end
        
        function onTextMessage(obj,message)
            fprintf('Message received:\n%s\n',message);
        end
        
        function onBinaryMessage(obj,bytearray)
            fprintf('Binary message received:\n');
            fprintf('Array length: %d\n',length(bytearray));
        end
        
        function onError(obj,message)
            fprintf('Error: %s\n',message);
        end
        
        function onClose(obj,message)
            fprintf('%s\n',message);
        end
    end
end