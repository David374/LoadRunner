vuser_init()
{
	
	web_reg_save_param("userSession",
	                   "LB=\"userSession\" value=\"",
	                   "RB=\"/>",
	                   LAST);
	
	
	web_url("WebTours", 
		"URL=http://localhost:8070/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
		 
	
	lr_start_transaction("UC01_TR01_Login");
	
    
	web_submit_data("login.pl", 
		"Action=http://localhost:8070/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=58", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);
	
	
	
	return 0;
}
