Action()
{
	int x = 1;
    int passengers = (rand()%4) + 1;
	
	lr_save_int(passengers, "numPassengers");
	
	
	lr_think_time(5);

	lr_start_transaction("TR02_Itinerary");
	
	web_reg_save_param("flightID",
    "lb=<input type=\"hidden\" name=\"flightID\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);

    web_reg_save_param("cgifield",
    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:8070/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR02_Itinerary",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("TR03_cancel_tickets"); 
	
	
	lr_param_sprintf("clipboard",
    "%s=on&",
    lr_eval_string("{flightID_count}")); 
	
    lr_save_string("", "clipboard");
	
	for (x=1; x<=3; x++) 
    {
        lr_param_sprintf("clipboard", "%s%d=on&", lr_eval_string("{clipboard}"), x);
    }
	
    for (x=1;x<=atoi(lr_eval_string("{flightID_count}"));x++)
    {
        lr_param_sprintf("clipboard",
        "%sflightID=%s&",
        lr_eval_string("{clipboard}"),
        lr_paramarr_idx("flightID",x));
        

        lr_param_sprintf("clipboard",
        "%s.cgifields=%s&",
        lr_eval_string("{clipboard}"),
        lr_paramarr_idx("cgifield",x));
        
    }

    
    lr_save_string(lr_eval_string("{clipboard}removeFlights.x=36&removeFlights.y=4"), "par"); 


    lr_save_string(lr_eval_string(lr_eval_string("{flightID_{flightID_count}}")),
    "c_cancelflight");
	
	
	web_custom_request("itinerary.pl",
    "URL=http://localhost:8070/cgi-bin/itinerary.pl",
    "Method=POST",
    "Resource=0",
    "RecContentType=text/html",
    "Referer=http://localhost:8070/cgi-bin/itinerary.pl",
    "Snapshot=t23.inf",
    "Mode=HTTP",
    "Body={par}",
    LAST);   


	lr_end_transaction("TR03_cancel_tickets",LR_AUTO); 

	lr_think_time(5);

	lr_start_transaction("TR04_Flights");
	
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

	web_url("Search Flights Button", 
		"URL=http://localhost:8070/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:8070/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("TR04_Flights",LR_AUTO);

	lr_think_time(5); 
	

	lr_start_transaction("TR05_Find_Flight");
	
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
		"Snapshot=t8.inf", 
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
		"Name=findFlights.x", "Value=35", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("TR05_Find_Flight",LR_AUTO);

	lr_think_time(5);

	return 0;
}