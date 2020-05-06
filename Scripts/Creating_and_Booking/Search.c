Search()
{
	int passengers = (rand()%4) + 1;
	
	lr_save_int(passengers, "numPassengers");
	
	
	
	lr_start_transaction("UC01_TR02_Flights");
	
	
	web_reg_save_param("cities",
	                   "LB=\"\>",
	                   "RB=</option>",
	                   "ORD=ALL",
	                   LAST);
	
	
	web_reg_save_param("departDate",
                       "LB=\"departDate\" value=\"",
                       "RB=\" size=",
                       LAST); 
	
	
	web_reg_save_param("returnDate",
                       "LB=\"returnDate\" value=\"",
                       "RB=\" size=",
                       LAST);
	
	
	web_reg_save_param("randomSeatP",
                       "LB=\"seatPref\" value=\"",
                       "RB=\" />",
                       "ORD=ALL",
                       LAST);
	
	
	web_reg_save_param("randomSeatT",
                       "LB=\"seatType\" value=\"",
                       "RB=\" />",
                       "ORD=ALL",
                       LAST);
	
	
	web_reg_save_param("seatPref",
                       "LB=\"seatPref\" value=\"",
                       "RB=\" />",
                       "ORD=ALL",
                       LAST);
	
	
	web_reg_save_param("seatType",
                       "LB=\"seatType\" value=\"",
                       "RB=\" />",
                       "ORD=ALL",
                       LAST);
	
	
	web_url("welcome.pl", 
		"URL=http://localhost:8070/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Flights",LR_AUTO);
	
	lr_think_time(5);
	
	
	
	lr_start_transaction("UC01_TR03_Find_Flight");
	
	web_reg_save_param("outboundFlight",
                       "LB=\"outboundFlight\" value=\"",
                       "RB=\" checked=",
                       LAST);

	
	lr_save_string(lr_paramarr_random("cities"),"depart");
	lr_save_string(lr_paramarr_random("cities"),"arrive");
	
	while (!strcmp(lr_eval_string("{depart}"), lr_eval_string("{arrive}"))){
	       	lr_save_string(lr_paramarr_random("cities"),"depart");
	       	lr_save_string(lr_paramarr_random("cities"),"arrive");
	       }
	
	
	lr_save_string(lr_paramarr_random("randomSeatP"),"seatPref");
	lr_save_string(lr_paramarr_random("randomSeatT"),"seatType");
				

	web_submit_data("reservations.pl", 
		"Action=http://localhost:8070/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM,  
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=66", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR03_Find_Flight",LR_AUTO);

	lr_think_time(5);
	
	return 0;
}
