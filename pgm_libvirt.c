#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

int main(int argc, char *argv[])
{
    virConnectPtr conn;
    virDomainPtr vdptr;
    int i=-1,choice; 	
    char *host;
    conn = virConnectOpen("xen:///");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to xen:///\n");
        return 1;
    }
    //host = virConnectGetHostname(conn);

    vdptr=virDomainLookupByName(conn,"ubuntu_new");
    printf("\n 1.Start \n 2.Suspend\n 3.Resume \n 4.Shutdown\n");

    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice) {

        case 1:
            /* Start */

            i=virDomainCreate(vdptr);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");
            }
            break;


        case 2:

            /* suspend*/	    
            i=virDomainSuspend(vdptr);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;


        case 3:

            /*resume*/
            i=virDomainResume(vdptr);
            if(i==0)
            {	
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;

        case 4:
           
            /*shutdown*/
            i=virDomainDestroy(vdptr);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;        

         default:
        
            printf("INVALID");


            virConnectClose(conn);
            return 0;
    }
}
