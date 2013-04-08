varying vec4 color;

void main(void)
{
	//this is a default vertex shader, don't modify the position
	//gl_Position = ftransform();
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    
	//.. and passes the  texture coordinates along to the fragment shader
	gl_TexCoord[0] = gl_MultiTexCoord0;
    
    color = gl_Color;
}
