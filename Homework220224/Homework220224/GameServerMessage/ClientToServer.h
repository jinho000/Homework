#pragma once
#include "GameServerMessage.h"

class sdfsdfMessage : public GameServerMessage                    
{                                                               
public:                                                         
	int f;
	int dff ;
	int ssdfsdf;
                                                                
public:                                                         
    sdfsdfMessage()                                               
        : GameServerMessage(MessageId::sdfsdf)                    
        , f()
        , dff()
        , ssdfsdf()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~sdfsdfMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(f) + DataSizeCheck(dff) + DataSizeCheck(ssdfsdf);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << f;
        _Serializer << dff;
        _Serializer << ssdfsdf;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> f;
        _Serializer >> dff;
        _Serializer >> ssdfsdf;

    }                                                           
};                                                              

