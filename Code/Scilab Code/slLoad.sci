//*****************************************************************************
//*** slLoad
//*****************************************************************************
function slLoad()
    slFuncs(1,1)= link("siseli.dll","version","c");
    slFuncs(1,2)= link("siseli.dll","mount","c");
    slFuncs(1,3)= link("siseli.dll","umount","c");
    slFuncs(1,4)= link("siseli.dll","check","c");
    slFuncs(1,5)= link("siseli.dll","config","c");
    slFuncs(1,6)= link("siseli.dll","open","c");
    slFuncs(1,7)= link("siseli.dll","close","c");
    slFuncs(1,8)= link("siseli.dll","sendb","c");
    slFuncs(1,9)= link("siseli.dll","senda","c");
    slFuncs(1,10)=link("siseli.dll","count","c");
    slFuncs(1,11)=link("siseli.dll","recvb","c");
    slFuncs=resume(slFuncs)
endfunction
//*****************************************************************************
//*** slVersion
//*****************************************************************************
function res=slVersion()
    res=fort("version","out",[1,1],1,"i")/10
endfunction    


//*****************************************************************************
//*** slUnload
//*****************************************************************************
function slUnload()
    for i=1:size(slFuncs,2)
        ulink(slFuncs(i))
    end
    clear slFuncs
endfunction    


//*****************************************************************************
//*** slMount
//*****************************************************************************
function res=slMount(nHandle)
    res=fort("mount",nHandle,1,"i","out",[1,1],2,"i")
endfunction


//*****************************************************************************
//*** slUMount
//*****************************************************************************
function res=slUMount(nHandle)
    res=fort("umount",nHandle,1,"i","out",[1,1],2,"i")
endfunction


//*****************************************************************************
//*** slCheck
//*****************************************************************************
function res=slCheck(nHandle, nPort)
    res=fort("check",nHandle,1,"i",nPort,2,"i","out",[1,1],3,"i")
endfunction


//*****************************************************************************
//*** slConfig
//*****************************************************************************
function res=slConfig(nHandle, nBaud, nBits, nPar, nStop)
    res=fort("config",nHandle,1,"i",nBaud,2,"i",nBits,3,"i",nPar,4,"i",nStop,5,"i","out",[1,1],6,"i")
endfunction


//*****************************************************************************
//*** slOpen
//*****************************************************************************
function res=slOpen(nHandle, nPort)
    res=fort("open",nHandle,1,"i",nPort,2,"i","out",[1,1],3,"i")
endfunction


//*****************************************************************************
//*** slClose
//*****************************************************************************
function res=slClose(nHandle)
    res=fort("close",nHandle,1,"i","out",[1,1],2,"i")
endfunction


//*****************************************************************************
//*** slSendByte
//*****************************************************************************
function res=slSendByte(nHandle, nByte)111
    res=fort("sendb",nHandle,1,"i",nByte,2,"i","out",[1,1],3,"i")
endfunction


//*****************************************************************************
//*** slSendArray
//*****************************************************************************
function res=slSendArray(nHandle, nByte, nLength)
    res=fort("senda",nHandle,1,"i",nByte,2,"i",nLength,3,"i","out",[1,1],4,"i")
endfunction
//*****************************************************************************
//*** slCount
//*****************************************************************************
function res=slCount(nHandle)
    res=fort("count",nHandle,1,"i","out",[1,1],2,"i")
endfunction


//*****************************************************************************
//*** slCount
//*****************************************************************************
function res=slReadByte(nHandle, nBlock)
    res=fort("recvb",nHandle,1,"i",nBlock,2,"i","out",[1,1],3,"i")
endfunction


//CameraImage=imread('C:\Documents and Settings\Kishaloy\Desktop\embedded\a.bmp');
//camopen();
//moon = imresize(CameraImage,[100 75]);
//[rows, cols]=size(moon);

tolerancePixels_xaxis = 3;  			// Setting the tolarence value in x-axis
tolerancePixels_yaxis = 3;			// Setting the tolarence value in y-axis
distanceFromReferenceUpperThreshold = 390;	// The Upper threshold from where the bot will draw the even lines
distanceFromReferenceLowerThreshold = 185;	// The Lower threshold from where the bot will draw the odd lines
partitioningThreshold =(distanceFromReferenceUpperThreshold+distanceFromReferenceLowerThreshold)/2;	// the mid of the upper & lower threshold

while 1
  
      slSendByte(1,ascii('d'));				// send done
      disp("done");
  sleep(2000);
end,

  
