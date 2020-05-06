vuser_end()
{
	
	lr_start_transaction("TR05_Sign_Off");

	web_url("SignOff Button", 
		"URL=http://localhost:8070/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR05_Sign_Off",LR_AUTO);
	return 0;
}
