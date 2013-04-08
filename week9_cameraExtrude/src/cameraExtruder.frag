

//here are some example uniforms
uniform sampler2DRect image;
uniform float brightness;
uniform vec4 tint;

void main (void)
{
	//vec4 sample = texture2DRect(image, gl_TexCoord[0].st);
	//use the color tint as well as whatever ofSetColor() is set to
	//gl_FragData[0] = sample ;
    
    
    gl_FragColor = texture2DRect(image, gl_TexCoord[0].st);
    
    //gradient by textcoordinates
   // gl_FragColor = vec4(gl_TexCoord[0].s/850.0, gl_TexCoord[0].t/988.0, 0.0, 1.0);
}
