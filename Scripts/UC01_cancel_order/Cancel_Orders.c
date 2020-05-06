Cancel_Orders()
{
	int i = 1;
	
	lr_start_transaction("UC01_TR03_cancel_orders");
//	
	lr_param_sprintf("c_buffer",
    "%s=on&",
    lr_eval_string("{flightID_count}"));
	
	//lr_save_string("", "c_buffer");//!!!
    
	for (i=1;i<=3;i++)
    {
        lr_param_sprintf("c_buffer", "%s%d=on&", lr_eval_string("{c_buffer}"), i);
    }
	
    for (i=1;i<=atoi(lr_eval_string("{flightID_count}"));i++)
    {
        lr_param_sprintf("c_buffer",
        "%sflightID=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("flightID",i));
        

        lr_param_sprintf("c_buffer",
        "%s.cgifields=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("cgifield",i));
        
    }

    
    lr_save_string(lr_eval_string("{c_buffer}removeFlights.x=36&removeFlights.y=4"), "c_wcr");


    lr_save_string(lr_eval_string(lr_eval_string("{flightID_{flightID_count}}")),
    "c_cancelflight");

    //web_reg_find("Text={c_cancelflight}", "Fail=Found", LAST);
    
     web_custom_request("itinerary.pl_2",
    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
    "Method=POST",
    "Resource=0",
    "RecContentType=text/html",
    "Referer=http://localhost:1080/cgi-bin/itinerary.pl",
    "Snapshot=t23.inf",
    "Mode=HTTP",
    "Body={c_wcr}",
    LAST);   
    
	/*web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=170413-7782-JB", ENDITEM, 
		"Name=flightID", "Value=229670-15469-JB", ENDITEM, 
		"Name=flightID", "Value=296351-23191-JB", ENDITEM, 
		"Name=flightID", "Value=11128-3113-JB", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=36630969-390-JB", ENDITEM, 
		"Name=flightID", "Value=3663059299-46238-JB", ENDITEM, 
		"Name=flightID", "Value=0-53-JB", ENDITEM, 
		"Name=flightID", "Value=0-61-JB", ENDITEM, 
		"Name=9", "Value=on", ENDITEM, 
		"Name=flightID", "Value=3300096337-69315-JB", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=66", ENDITEM, 
		"Name=removeFlights.y", "Value=5", ENDITEM, 
		LAST);*/

	lr_end_transaction("UC01_TR03_cancel_orders",LR_AUTO);

	lr_think_time(33);
	
}
